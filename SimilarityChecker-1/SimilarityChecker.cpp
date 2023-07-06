#include <string>
#include <stdexcept>


using namespace std;

class SimilarityChecker
{
public:
	void assertIllegalArgument(const std::string& guessNumber)
	{
		for (char ch : guessNumber)
		{
			if (ch >= 'A' && ch <= 'Z')
				continue;
			throw invalid_argument("Must be number");
		}
	}

	int getPoint(const string& firstString, const string& secondString)
	{
		int point = 0;
		assertIllegalArgument(firstString);
		assertIllegalArgument(secondString);
		return point;
	}

	double calcLengthPoint(double shortsize, double longsize)
	{
		if (longsize / shortsize >= 2)
			return 0;
		return (1 - (longsize - shortsize) / shortsize) * MAX_LENGTH_SCORE;
	}

	void calcLongShort(const string& firstString, const string& secondString)
	{
		if (firstString.size() <= secondString.size())
		{
			longString = secondString;
			shortString = firstString;
		}
		else
		{
			longString = firstString;
			shortString = secondString;
		}
	}

	double getLengthPoint(const string& firstString, const string& secondString)
	{
		if (firstString.size() == secondString.size()) return MAX_LENGTH_SCORE;
		calcLongShort(firstString, secondString);
		return calcLengthPoint(shortString.size(), longString.size());
	}

private:
	string longString;
	string shortString;
	static int MAX_LENGTH_SCORE = 60;
};
