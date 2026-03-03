/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>

std::string kYourName = "Raphael Costeau"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> res_set;
  std::ifstream file;
  file.open(filename);
  std::string name;
  while (std::getline(file, name)) 
    res_set.insert(name);
  file.close();
  return res_set;
}

/**
 * This is the helper function to decide whether two names share initials
 * @param name      The given name.
 * @param student   The student's name.
 * @return          A bool variable to tell whether they share initials.
 */
bool share_initial(const std::string& name, const std::string& student) {
  std::string a1, a2, b1, b2;
  std::istringstream a(name);
  std::istringstream b(student);
  a >> a1 >> a2;
  b >> b1 >> b2;
  return (a1[0] == b1[0]) && (a2[0] == b2[0]);
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> res_queue;
  for (const auto& elem : students) {
    if (share_initial(name, elem))
      res_queue.push(&elem); 
  }
  return res_queue;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  while (matches.size() > 1) {
    auto sptr = matches.front();
    matches.pop();
    if ((*sptr).length() < 10) {
      return *sptr;
    }
  }
  auto sptr = matches.front();
  return *sptr;
  // auto sptr = matches.front();
  // return *sptr;
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
