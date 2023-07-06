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

