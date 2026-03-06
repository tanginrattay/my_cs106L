#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */

std::ostream& operator<<(std::ostream& os, const User& user) {
  os << "User(name=" << user._name << ", friends=[";
  for (int i = 0; i < user._size; i++) {
    if (i)
      os << ", " << user._friends[i];
    else 
      os << user._friends[i];
  }
  os << "])";
  return os;
} 

User::~User()
{
  delete[] this->_friends;
}

User::User(const User& user)
{
  this->_name = user._name;     //为什么可以访问private对象？
  this->_capacity = user._capacity;
  this->_size = user._size;
  this->_friends = new std::string[_capacity];
  for (size_t i = 0; i < _size; ++i) {
    _friends[i] = user._friends[i];
  }
}

User& User::operator=(const User& user)
{
  if (this == &user)
    return *this;

  std::string* newfriends = nullptr;
  if (user._capacity > 0) {
    newfriends = new std::string[user._capacity];
    for (size_t i = 0; i < user._size; ++i) {
      newfriends[i] = user._friends[i];
    }
  }

  delete[] _friends;
  this->_name = user._name;
  this->_capacity = user._capacity;
  this->_size = user._size;
  this->_friends = newfriends;
  return *this;
}

User& User::operator+=(User& user)
{
  this->add_friend(user._name);
  user.add_friend(this->_name);
  return *this;
}

bool User::operator<(const User& user) const
{
  return this->_name < user._name;
}
