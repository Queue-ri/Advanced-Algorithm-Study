#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C, N;

vector<int> slice(const vector<int>& v, int a, int b) {
	return vector<int>(v.begin() + a, v.begin() + b);
}

void postorder(const vector<int>& preorder, const vector<int>& inorder) {
	if (preorder.empty()) return;
	int root = preorder[0];
	int ps = preorder.size();
	int Lsub = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	
	int Rsub = ps - 1 - Lsub;

	postorder(slice(preorder, 1, Lsub + 1), slice(inorder, 0, Lsub));

	postorder(slice(preorder, Lsub + 1, ps), slice(inorder, Lsub + 1, ps));
	
	cout << root << " ";
	return;
}

int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N;
		vector<int> preorder, inorder;
		int node;
		for (int j = 0; j < N; j++) {
			cin >> node;
			preorder.push_back(node);
		}
		for (int j = 0; j < N; j++) {
			cin >> node;
			inorder.push_back(node);
		}

		postorder(preorder, inorder);
		cout << endl;
	}
	return 0;
}
