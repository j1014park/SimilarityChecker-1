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

	int getLengthPoint(const string& firstString, const string& secondString)
	{
		if (firstString.length() == secondString.length()) return 60;
	}

private:
	string longString;
	string shortString;
};
