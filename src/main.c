#include "conversor.h"
#include <gtest/gtest.h>

TEST(Conversao_geral, Entrada_correta){
    EXPECT_EQ(1, computeNumber(convertArabic((char*)"i")));
    EXPECT_EQ(2, computeNumber(convertArabic((char*)"ii")));
    EXPECT_EQ(3, computeNumber(convertArabic((char*)"iii")));
    EXPECT_EQ(4, computeNumber(convertArabic((char*)"iv")));
    EXPECT_EQ(5, computeNumber(convertArabic((char*)"v")));
    EXPECT_EQ(6, computeNumber(convertArabic((char*)"vi")));
    EXPECT_EQ(7, computeNumber(convertArabic((char*)"vii")));
    EXPECT_EQ(8, computeNumber(convertArabic((char*)"viii")));
    EXPECT_EQ(9, computeNumber(convertArabic((char*)"ix")));
    EXPECT_EQ(10, computeNumber(convertArabic((char*)"x")));
}

int main(int argc, char **argv){
    
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
