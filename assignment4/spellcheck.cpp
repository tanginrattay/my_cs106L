#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  /* TODO: Implement this method */
  auto spaces = find_all(source.begin(), source.end(), [] (char c) {return std::isspace(c);});
  std::set<Token> tokens;
  auto d_first = std::inserter(tokens, tokens.end());
  std::transform(spaces.begin(), spaces.end() - 1, spaces.begin() + 1, d_first, [&source] (auto it1, auto it2) {
    return Token(source, it1, it2);
  });

  std::erase_if(tokens, [] (const Token& t) {
    return t.content.empty();
  });
  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  /* TODO: Implement this method */
  namespace rv = std::ranges::views;
  auto view = source
    | rv::filter([&dictionary] (Token t) { return !dictionary.contains(t.content); })
    | rv::transform([&dictionary] (Token t) {
      auto view2 = dictionary | rv::filter([&t] (std::string s) { return levenshtein(s, t.content) == 1; });
      std::set<std::string> suggestions(view2.begin(), view2.end());
      return Misspelling { t, suggestions};
    })
    | rv::filter([] (Misspelling m) { return !m.suggestions.empty(); });
  std::set<Misspelling> res(view.begin(), view.end());
  return res;
};

/* Helper methods */

#include "utils.cpp"