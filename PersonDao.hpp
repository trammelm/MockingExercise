//
//  personDao.hpp
//  test_gtest_2
//
//  Created by Kyle Griffin on 6/12/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#ifndef personDao_hpp
#define personDao_hpp

#include <stdio.h>
#include <string>

class Person;

class PersonDao {
public:
    virtual void save(Person *p) = 0;
    virtual Person find(std::string name) = 0;
    virtual void update(Person *p) = 0;
    virtual void remove(Person *p) = 0;
    virtual ~PersonDao() {};
};


#endif /* personDao_hpp */
