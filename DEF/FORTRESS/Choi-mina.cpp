#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int C, N;
int x[100], y[100], r[100];
int longest;	// leaf~leaf 길이 저장

struct Tree {
	vector<Tree*> child;
};

// 각 자식을 루트로 하는 서브트리 높이 계산
int height(Tree* root) {
	vector<int> heights;
	for (int i = 0; i < root->child.size(); i++)
		heights.push_back(height(root->child[i]));
	// 자식이 없다면 반환
	if (heights.empty()) return 0;

	sort(heights.begin(), heights.end());

	// 서브트리가 2개 이상인 경우
	if (heights.size() >= 2)
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	// 트리의 높이는 서브트리의 높이 + 1
	return heights.back() + 1;
}

//두 노드 사이의 가장 긴 경로의 길이를 계산
int solve(Tree* root) {
	longest = 0;

	//트리의 높이와 최대 leaf-leaf 경로 길이 중 큰 것을 선택
	int h = height(root);
	return max(longest, h);
}

//성벽 a가 성벽 b를 포함하는지 확인
bool enclose(int a, int b) {
	if (r[a] > r[b]) {
		int dx = x[a] - x[b];
		int dy = y[a] - y[b];
		if (pow(dx, 2) + pow(dy, 2) < pow(r[a] - r[b], 2))
			return true;
	}
	return false;
}

// parent는 child를 꼭 직접 포함해야 한다.
bool isChild(int parent, int child) {
	if (!enclose(parent, child)) return false;
	for (int i = 0; i < N; i++)
		if (i != parent && i != child &&
			enclose(parent, i) && enclose(i, child))
			return false;
	return true;
}

// 0을 루트로 하는 트리 생성
Tree *getTree(int root) {
	Tree* tmp = new Tree();
	for (int i = 0; i < N; i++) {
		if (isChild(root, i)) {
			// i 성벽이 root 성벽에 직접적으로 포함되어 있다면
			// 트리를 만들고 자손 목록에 추가한다
			tmp->child.push_back(getTree(i));
		}
	}
	return tmp;
}


int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> x[j] >> y[j] >> r[j];
		}
		// 모든 성벽을 포함하는 외벽 = 0
		Tree* Tree = getTree(0);
		cout << solve(Tree) << endl;
	}
	return 0;
}
