#include <string>
#include <vector>
#include <sstream>
#include <tuple>
#include <algorithm>
using namespace std;
//시간, 분, 차번호, in/out
typedef tuple<int, int, int, char>info;
typedef pair<int, int>info2;

vector<string> split(string input, char delimiter) {
	vector<string>result;
	stringstream mydata(input);
	string splitdata;

	while (getline(mydata, splitdata, delimiter)) {
		result.push_back(splitdata);
	}
	return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int n = records.size();
	vector<info>datas(n);
	vector<info2> result;

	//요금표
	int b_time = fees[0];
	int b_mon = fees[1];
	int p_time = fees[2];
	int p_mon = fees[3];

	for (int i = 0; i < n; i++) {
		vector<string> out = split(records[i], ' ');
		get<2>(datas[i]) = stoi(out[1]);//차번호
		get<3>(datas[i]) = out[2][0];//inout
		vector<string> time_out = split(out[0], ':');
		get<0>(datas[i]) = stoi(time_out[0]);//시간
		get<1>(datas[i]) = stoi(time_out[1]);//분   
	}

	//주차 요금 계산
	for (int i = 0; i < n; i++) {
		info v = datas[i];
		int i_h = get<0>(v);
		int i_m = get<1>(v);
		int i_car_n = get<2>(v);
		char in = get<3>(v);

		if (in == 'I') {
			int flag = 0;
			int time = 0;
			for (int j = i; j < n; j++) {
				info t = datas[j];
				int o_h = get<0>(t);
				int o_m = get<1>(t);
				int o_car_n = get<2>(t);
				char out = get<3>(t);

				if (out == 'O') {
					if (i_car_n == o_car_n) {
						//요금계산
						if (o_m >= i_m) time = o_m - i_m;
						else {
							time = 60 - i_m + o_m;
							o_h--;
						}
						time += (o_h - i_h) * 60;
						flag = 1;
						break;
					}
				}
			}

			if (flag == 0) {//23:59분 출차
				time = 59 - i_m;
				time += (23 - i_h) * 60;
				flag = 1;
			}

			//차량 등록
			int flag2 = 0;
			for (int p = 0; p < result.size(); p++) {
				if (result[p].first == i_car_n) {
					flag2 = 1;
					result[p].second += time;
				}
			}
			if (flag2 == 0) result.push_back(info2(i_car_n, time));
		}
	}
	sort(result.begin(), result.end());

	//요금계산
	for (int i = 0; i < result.size(); i++) {
		int time = result[i].second;
		int money = 0;
		if (time <= b_time) money = b_mon;
		else {
			money = b_mon;
			time -= b_time;
			if (time % p_time == 0)money += (time / p_time) * p_mon;
			else money += (time / p_time + 1) * p_mon;
		}
		answer.push_back(money);
	}
    return answer;
}