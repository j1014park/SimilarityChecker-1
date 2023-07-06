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
		return (1 - (longsize - shortsize) / shortsize) * 60;
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
		if (firstString.size() == secondString.size()) return 60;
		calcLongShort(firstString, secondString);
		return calcLengthPoint(shortString.size(), longString.size());
	}

private:
	string longString;
	string shortString;
};
