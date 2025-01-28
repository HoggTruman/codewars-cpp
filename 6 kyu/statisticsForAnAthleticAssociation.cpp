// https://www.codewars.com/kata/55b3425df71c1201a800009c

#include <string>
#include <vector>
#include <algorithm>
#include <numeric>


class Stat
{
	public:
		static std::string stat(const std::string& str)
		{
			if (str.size() == 0)
			{
				return "";
			}

			std::vector<int> times{};
			size_t i{ 0 };

			do
			{
				if (std::isdigit(str[i]))
				{
					size_t next = str.find(',', i);
					
					if (next == std::string::npos)
					{
						next = str.size();
					}

					std::string time{ str.substr(i, next - i) };
					times.push_back(timeToSeconds(time));
					i = next;
				}
			} 
			while (++i < str.size());

			std::sort(times.begin(), times.end());
			std::string range{ secondsToTime(rangeFromSorted(times)) };
			std::string median{ secondsToTime(medianFromSorted(times)) };
			std::string mean{ secondsToTime(Stat::mean(times))};

			return "Range: " + range +
				" Average: " + mean +
				" Median: " + median;
		}


	private:
		static const int SECONDS_PER_HOUR{ 3600 };
		static const int SECONDS_PER_MINUTE{ 60 };


		static int timeToSeconds(std::string& time)
		{
			std::string hours{ time.substr(0, time.find('|'))};

			time.erase(0, hours.size() + 1);

			std::string minutes{ time.substr(0, time.find('|'))};
			std::string seconds{ time.substr(minutes.size() + 1)};

			return std::stoi(hours) * SECONDS_PER_HOUR + 
				std::stoi(minutes) * SECONDS_PER_MINUTE +
				std::stoi(seconds);
		}


		static std::string secondsToTime(const int& secs)
		{
			int hours{ secs / SECONDS_PER_HOUR };
			int minutes{ (secs % SECONDS_PER_HOUR) / SECONDS_PER_MINUTE };
			int seconds{ secs % SECONDS_PER_MINUTE };

			return partToString(hours) + '|' +
				partToString(minutes) + '|' +
				partToString(seconds);
		}


		static std::string partToString(int part)
		{
			std::string result = std::to_string(part);
			return result.size() == 1 ? '0' + result : result;
		}


		static int rangeFromSorted(const std::vector<int>& vec)
		{
			return vec.size() == 1?
				vec.front():
				vec.back() - vec.front();
		}


		static int medianFromSorted(const std::vector<int>& vec)
		{
			size_t n{ vec.size() };
			return n % 2 == 0 ?
				(vec[n / 2] + vec[n / 2 - 1]) / 2 :
				vec[n / 2];
		}


		static int mean(const std::vector<int>& vec)
		{
			return std::reduce(vec.begin(), vec.end()) / 
				static_cast<int>(vec.size());
		}
};
