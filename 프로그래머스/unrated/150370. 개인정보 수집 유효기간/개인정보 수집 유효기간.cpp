#include <string>
#include <vector>
#include <sstream>
#include <tuple>
#include <algorithm>

using namespace std;

typedef pair<char, int> termsdata;//종류, 기간(1~100)
typedef tuple<char, int, int, int> pridata;//종류, 년, 월, 일

//spilt사용해서 벡터에 집어넣음
vector<string> split(string input, char delimiter) {
	vector<string> result;
	stringstream mydata(input);
	string datasplit;

	while (getline(mydata, datasplit, delimiter)) {
		result.push_back(datasplit);
	}
	return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
	vector<int> answer;

	//today 날짜 split 저장
	int t_year, t_mon, t_day;
	vector<string> t_info = split(today, '.');
	t_year = stoi(t_info[0]);//int로 변경
	t_mon = stoi(t_info[1]);//int로 변경
	t_day = stoi(t_info[2]);//int로 변경

	//term 정보 저장
	vector<termsdata> terms_info;
	for (int i = 0; i < terms.size(); i++) {
		vector<string> term_split = split(terms[i], ' ');
		int a;
		char b;
		a = stoi(term_split[1]);
		b = term_split[0][0];//string -> char로 변환
		// strcpy(ch2, str2.c_str());
		terms_info.push_back(termsdata(b, a));
	}

	//privacies 정보 저장
	vector<pridata> pri_info;
	for (int i = 0; i < privacies.size(); i++) {
		vector<string> privacies_split = split(privacies[i], ' ');
		char b;
		int y, m, d;
		//날짜
		vector<string> date_split = split(privacies_split[0], '.');
		y = stoi(date_split[0]);
		m = stoi(date_split[1]);
		d = stoi(date_split[2]);
		//약관 종류
		b = privacies_split[1][0];//string -> char로 변환

		pri_info.push_back(make_tuple(b, y, m, d));
	}
	/*정보 정리 완료*/

	/*탐색 시작*/
	for (int i = 0; i < pri_info.size(); i++) {
		//pri 수집 일자
		int f_year, f_mon, f_day;
		f_year = get<1>(pri_info[i]);
		f_mon = get<2>(pri_info[i]);
		f_day = get<3>(pri_info[i]);

		int type_mon;//해당 약정 종류에 따른 기간 저장
		for (int j = 0; j < terms_info.size(); j++) {
			if (get<0>(pri_info[i]) == terms_info[j].first) {
				type_mon = terms_info[j].second;
				break;
			}
		}
		//기간이 1~100이므로 년, 월 로 나눠서 저장
		int p_year, p_mon;
		p_year = type_mon / 12;
		p_mon = type_mon % 12;

		//f_year, f_mon,f_day 최대 유효기간까지 저장 
		f_day--;
		if (f_day == 0) {
			f_mon--;
			f_day = 28;
		}
		f_mon += p_mon;
		if (f_mon > 12) {//12달 넘어갈 때
			f_year++;
			f_mon -= 12;
		}
		f_year += p_year;

		//f(만료일)와 t(오늘) 비교
		if (f_year == t_year) {
			if (f_mon == t_mon) {
				if (f_day < t_day) {
					answer.push_back(i + 1);
				}
			}
			else if (f_mon < t_mon) {
				answer.push_back(i + 1);
			}
		}
		else if (f_year < t_year) {
			answer.push_back(i + 1);
		}
	}
	sort(answer.begin(), answer.end());//오름차순 정렬

	return answer;
}