#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
int C, N;

vector<vector<int>> graph;
vector<int> visited, order;

// 정렬된 단어들 검사하면서 알파벳 선후관계를 표현하는 그래프 생성
void makeGraph(const vector<string>& words) {
	graph = vector<vector<int>>(26, vector<int>(26, 0));
	for (int i = 1; i < words.size(); i++) {
		int j = i - 1;
		int l = min(words[i].size(), words[j].size());

		for (int k = 0; k < l; ++k) {
			if (words[j][k] != words[i][k]) {
				int a = words[j][k] - 'a';
				int b = words[i][k] - 'a';

				graph[a][b] = 1;
				break;
			}
		}
	}
}

void dfs(int here) {
	// 방문한 것 표시
	visited[here] = 1;

	for (int next = 0; next < graph.size(); ++next)
		if (graph[here][next] && !visited[next])
			dfs(next);
	order.push_back(here);
}

// graph에 주어진 그래프를 위상정렬한 결과를 반환한다
vector<int> topologicalSort(void) {
	int N = graph.size();
	visited = vector<int>(N, 0);

	order.clear();
	for (int i = 0; i < N; i++)
		if (!visited[i])
			dfs(i);
	// dfs 결과를 뒤집음.
	reverse(order.begin(), order.end());

	// 역방향(오른쪽->왼쪽) 간선 확인
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			// 그래프가 DAG가 아니라면(역방향O) 빈 벡터를 반환
			if (graph[order[j]][order[i]])
				return vector<int>();
	// 사이클이 없는 경우라면 dfs에서 얻은 순서를 반환
	return order;
}


int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		vector<string> words(N);
		for (int j = 0; j < N; j++)
			cin >> words[j];

		makeGraph(words);
		vector<int> result = topologicalSort();

		// 알파벳들의 순서에 모순이 있는 경우
		if (result.empty())
			cout << "INVALID HYPOTHESIS";
		// 모순이 없는 경우
		else
			for (int j = 0; j < result.size(); j++)
				cout << char(result[j] + 'a');
		cout << '\n';
	}
	return 0;
}
