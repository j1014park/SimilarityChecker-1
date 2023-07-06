#include "pch.h"
#include "../SimilarityChecker-1/SimilarityChecker.cpp"
using namespace std;

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker similarityChecker;
	void assertIllegalArgument(string firstString, string secondString)
	{
		try
		{
			similarityChecker.getPoint(firstString,secondString);
			FAIL();
		}
		catch (exception e)
		{
		}
	}
};

TEST_F(SimilarityCheckerFixture, ThrowExceptionInvalidCase1) {
	assertIllegalArgument("1ABC","CCD");
}

TEST_F(SimilarityCheckerFixture, ThrowExceptionInvalidCase2) {
	assertIllegalArgument("CCD","C1CD");
}

TEST_F(SimilarityCheckerFixture, ReturnCheckWhenCallgetSameLength) {
	EXPECT_EQ(60, similarityChecker.getLengthPoint("AAA", "BBB"));
}

TEST_F(SimilarityCheckerFixture, ReturnCheckWhenCallgetLength2_3) {
	EXPECT_EQ(30, similarityChecker.getLengthPoint("AA", "BBD"));
}

TEST_F(SimilarityCheckerFixture, ReturnCheckWhenCallgetLength2_4) {
	EXPECT_EQ(0, similarityChecker.getLengthPoint("AA", "BBDD"));
}

TEST_F(SimilarityCheckerFixture, ReturnCheckWhenCallgetAlpha1_1) {
	EXPECT_EQ(0, similarityChecker.getAlphabatPoint("A", "B"));
}

TEST_F(SimilarityCheckerFixture, ReturnCheckWhenCallgetAlpha3_3) {
	EXPECT_EQ(40, similarityChecker.getAlphabatPoint("ASD", "DSA"));
}

TEST_F(SimilarityCheckerFixture, ReturnCheckWhenCallgetAlpha_partScore) {
	EXPECT_EQ(20, similarityChecker.getAlphabatPoint("AA", "AAE"));
}


 