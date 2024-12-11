//
// Created by tobias on 21.11.16.
//

#ifndef VDSPROJECT_TESTS_H
#define VDSPROJECT_TESTS_H

#include <gtest/gtest.h>
#include "../Manager.h"

class ManagerTests : public testing::Test {
    protected:
        ClassProject::Manager man;
};

TEST_F(ManagerTests, testTrue) {
    EXPECT_EQ(man.True(),1);
};

TEST_F(ManagerTests, testFalse) {
    EXPECT_EQ(man.False(),0);
};

TEST_F(ManagerTests, testCreateVar) {
    EXPECT_EQ(man.createVar("a"),2);
    EXPECT_EQ(man.createVar("a"),2);
    EXPECT_EQ(man.createVar("b"),3);
    EXPECT_EQ(man.createVar("c"),4);
    EXPECT_EQ(man.createVar("b"),3);
    EXPECT_EQ(man.createVar("a"),2);
};

TEST_F(ManagerTests, testIsConstant) {
    EXPECT_EQ(man.isConstant(0),1);
    EXPECT_EQ(man.isConstant(1),1);
    man.createVar("a");
    EXPECT_EQ(man.isConstant(0),1);
    EXPECT_EQ(man.isConstant(1),1);
    EXPECT_EQ(man.isConstant(2),0);
    man.createVar("b");
    EXPECT_EQ(man.isConstant(0),1);
    EXPECT_EQ(man.isConstant(1),1);
    EXPECT_EQ(man.isConstant(2),0);
};

#endif
