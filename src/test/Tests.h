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
        ClassProject::BDD_ID falseID = man.False();
        ClassProject::BDD_ID trueID = man.True();
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
    EXPECT_EQ(man.isConstant(falseID),true);
    EXPECT_EQ(man.isConstant(trueID),true);
    ClassProject::BDD_ID aID = man.createVar("a");
    EXPECT_EQ(man.isConstant(falseID),true);
    EXPECT_EQ(man.isConstant(trueID),true);
    EXPECT_EQ(man.isConstant(aID),false);
    ClassProject::BDD_ID bID = man.createVar("b");
    EXPECT_EQ(man.isConstant(falseID),true);
    EXPECT_EQ(man.isConstant(trueID),true);
    EXPECT_EQ(man.isConstant(aID),false);
    EXPECT_EQ(man.isConstant(bID),false);
};

TEST_F(ManagerTests, testIsVariable) {
    EXPECT_EQ(man.isVariable(falseID),false);
    EXPECT_EQ(man.isVariable(trueID),false);
    ClassProject::BDD_ID aID = man.createVar("a");
    EXPECT_EQ(man.isVariable(falseID),false);
    EXPECT_EQ(man.isVariable(trueID),false);
    EXPECT_EQ(man.isVariable(aID),true);
    ClassProject::BDD_ID bID = man.createVar("b");
    EXPECT_EQ(man.isVariable(falseID),false);
    EXPECT_EQ(man.isVariable(trueID),false);
    EXPECT_EQ(man.isVariable(aID),true);
    EXPECT_EQ(man.isVariable(bID),true);
}

#endif
