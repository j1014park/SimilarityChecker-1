#include <string>
#include <stdexcept>

#include <map>



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

	double getPoint(const string& firstString, const string& secondString)
	{
		double point = 0;
		assertIllegalArgument(firstString);
		assertIllegalArgument(secondString);
		point += getLengthPoint(firstString, secondString);

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

	double getAlphabatPoint(const string& firstString, const string& secondString)
	{
		//µîÀåÇÏ´Â ¾ËÆÄºª °¹¼ö
		int firstAlpha = 0;
		int secondAlpha = 0;
		map<char,int> sameChar;
		map<char,int> uniqueChar;
		sameChar.clear();
		uniqueChar.clear();
		for (const char first : firstString)
		{
			for (const char second : secondString)
			{
				if(first == second)
				{
					sameChar.insert(pair<char, int>{first, 1});
					uniqueChar.insert(pair<char, int>{first, 1});
				}

				if(first != second)
				{					
					uniqueChar.insert(pair<char, int>{first, 1});
					uniqueChar.insert(pair<char, int>{second, 1});
				}
			}
		}

		double sameCnt = sameChar.size();
		double totalCnt = uniqueChar.size();

		return (sameCnt/totalCnt)*40;
	}

private:
	string longString;
	string shortString;
	const int MAX_LENGTH_SCORE = 60;
};
