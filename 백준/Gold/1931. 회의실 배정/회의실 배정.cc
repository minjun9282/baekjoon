#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting {
	int start_time;
	int end_time;
	int duration;
};

bool compare_meetings(struct Meeting& a, struct Meeting& b) {
	if (a.end_time == b.end_time) {
		return a.start_time < b.start_time;
	}
	return a.end_time < b.end_time;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	vector<Meeting> meetings;

	for (int i = 0; i < N; i++) {
		int start, end, duration;
		cin >> start >> end;
		duration = end - start;
		meetings.push_back({ start, end, duration});
	}

	sort(meetings.begin(), meetings.end(), compare_meetings);
	int result = 0;
	int temp_end_time = meetings[0].end_time;
	result += 1;
	for (int i = 1; i < N; i++) {
		if (meetings[i].start_time >= temp_end_time) {
			result += 1;
			temp_end_time = meetings[i].end_time;
		}
	}
	cout << result << '\n';

	return 0;
}