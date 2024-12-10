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

#endif
