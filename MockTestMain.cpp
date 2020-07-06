//
//  MockTestMain.cpp
//  test_gtest_2
//
//  Created by Kyle Griffin on 6/12/20.
//  Copyright © 2020 Kyle Griffin. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "Person.hpp"
#include "PersonDaoMock.hpp"

using testing::Return;
using std::string;

TEST(Person_Test, save) {
    //test data
 
    
    //STUDENT WORK
    //mock setup
    //wiring

    /*PersonDaoMock* mockDao;
    Person p("Dave", 40);
    p.setDao(mockDao);
    EXPECT_CALL(mockDao, save(p));*/

    PersonDaoMock* mockDao = new PersonDaoMock();
    int age = 40;
    Person *p = new Person("Dave", age);
    p->setDao(mockDao);
    EXPECT_CALL(*mockDao, save(p));

    p->save();

    EXPECT_EQ(p->getName(), "Dave");

    mockDao = NULL;
    delete mockDao;

    //execution
   //p.save();

    //STUDENT WORK
    //test
    //EXPECT_CALL(b,stepOne(expected_input)).Times(1).WillOnce(Return(return_val));
    //setAge, update, save, remove, find 
}

// MORE TESTS -- update, find, remove, constructor(no mocks), etc.
TEST(Person_Test, update) {


    PersonDaoMock* mockDao = new PersonDaoMock();
    int age = 32;
    Person* p = new Person("Bob", age);
    p->setDao(mockDao);
    EXPECT_CALL(*mockDao, update(p));

    p->update();

    //EXPECT_EQ(p->getName(), "Bob");
    //EXPECT_EQ(p->getAge(), age);

}
TEST(Person_Test, find) {
    
    PersonDaoMock* mockDao = new PersonDaoMock();
    int age = 32;
    string bob = "Bob";
    Person* p = new Person(bob, age);
    p->setDao(mockDao);
    EXPECT_CALL(*mockDao, find(bob)).Times(1).WillOnce(Return(*p));
   
   
    Person* b = &(p->find(bob));
    //p->setDao(NULL);

    /*EXPECT_EQ(p->getName(), "Bob");
    EXPECT_EQ(p->getAge(), age);*/
}
TEST(Person_Test, remove) {

    PersonDaoMock* mockDao = new PersonDaoMock();
    int age = 32;
    Person* p = new Person("Bob", age);
    p->setDao(mockDao);
    EXPECT_CALL(*mockDao, remove(p));
    p->remove();
    /*EXPECT_EQ(p->getName(), "");
    EXPECT_EQ(p->getAge(), 0);*/

}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

