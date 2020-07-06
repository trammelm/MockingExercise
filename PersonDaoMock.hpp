// PersonDaoMock.hpp
#ifndef PersonDaoMock_h
#define PersonDaoMock_h


#include <stdio.h>
#include "PersonDao.hpp"
#include <vector>

class Person;

class PersonDaoMock: public PersonDao {
public:
  // YOUR CODE
    PersonDaoMock() {};
    ~PersonDaoMock() {};

    //void save(Person *p)
    MOCK_METHOD(void, save, (Person *p), (override));

    //Person find(std::string name)
    MOCK_METHOD(Person, find, (std::string name), (override));

    //void update(Person* p)
    MOCK_METHOD(void, update, (Person *p), (override));

    //void remove(Person* p)
    MOCK_METHOD(void, remove, (Person *p), (override));
};

#endif /* PersonDaoMock_h */
