# FESTIVAL(록 페스티벌) ![](https://img.shields.io/badge/-easy-brightgreen)
ID | Time Limit | Memory Limit | Source | Category
:-:|:----------:|:------------:|:------:|:--------:
[FESTIVAL](https://algospot.com/judge/problem/read/FESTIVAL) | 20000ms | 65536kb | [알고리즘 문제 해결 전략](https://algospot.com/judge/problem/list/?source=%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98%20%EB%AC%B8%EC%A0%9C%20%ED%95%B4%EA%B2%B0%20%EC%A0%84%EB%9E%B5) | [spoiler](https://algospot.com/judge/problem/list/?tag=%EA%B5%AC%ED%98%84)
- 1주차 문제 ([#1][i1])

## ✔ 풀이 현황
ID | Time | File Name | Review | PR | Question
:-:|:----:|:---------:|:------:|:--:|:--------:
[Scaachan](https://github.com/Scaachan) | 28ms | Scaachan_2.cpp |  |  |
[Scaachan](https://github.com/Scaachan) | 48ms | Scaachan.cpp | **AC([#12][i12])** |  |
[yujungee](https://github.com/yujungee) | 56ms | yujungee.cpp | **AC([#7][i7])** |  |
[hanjuuuuuu](https://github.com/hanjuuuuuu) | 68ms | hanjuuuuuu.cpp | WA([#4][i4]) | **AC([#40][i40])** | [#17][i17]
[dakyommii](https://github.com/dakyommii) | 5188ms | dakyommii.cpp | RTE([#10][i10]) | **AC([#44][i44])** |

[i1]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/1
[i4]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/4
[i7]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/7
[i10]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/10
[i12]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/12
[i17]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/17
[i40]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/40
[i44]: https://github.com/Scaachan/Advanced-Algorithm-Study/issues/44

- **수행시간이 짧은 순**으로 나열합니다.
- push된 풀이코드는 모두 **AC 풀이**입니다.
- PR은 해당 주차에 틀린 풀이를 이후 수정하여 AC 받은 내역을 기록한 것입니다.
- PR이 있는 AC Review는 PR 이후 별도로 작성한 것입니다.

## 📖 문제
커다란 공연장을 빌려서 록 페스티벌을 개최하려고 합니다. 이 페스티벌은 여러 날 동안 진행되며, 하루에 한 팀의 밴드가 공연장에서 콘서트를 하게 됩니다. 전체 밴드를 몇 팀 섭외할 지는 아직 결정하지 않았지만, 페스티벌의 간판 스타인 L개의 팀은 이미 섭외가 끝난 상태입니다. 따라서 페스티벌은 최소 L일 이상 진행하게 됩니다.

이번에 사용할 공연장은 하루 빌리는 데 드는 비용이 매일 매일 다릅니다. 때문에 공연 일정을 잘 정해서 공연장 대여 비용을 줄이려고 합니다. 앞으로 N일간의 공연장 대여 비용을 알고 있다고 합시다. 이 중 L일 이상을 연속해서 대여하되, 공연장을 하루 빌리는 데 드는 평균 비용을 최소화하려면 어떻게 공연장을 빌려야 할까요?

예를 들어 앞으로 6일간 공연장을 빌리는 데 드는 비용이 각 {3, 1, 2, 3, 1, 2}라고 합시다. 이미 세 팀을 섭외했다고 하면, 3일 대신 4일 동안 공연을 진행해서 평균 비용을 더 저렴하게 할 수 있습니다. 3일 동안의 평균 대여 비용을 최소화하는 방법은 2일째부터 4일째까지 공연장을 대여하는 것인데, 이 때 하루 평균 (1+2+3)/3 = 2의 비용이 듭니다. 반면 2일째부터 5일째까지 공연장을 대여하면 평균 비용이 (1+2+3+1)/4 = 7/4밖에 되지 않습니다.

### 입력
입력의 첫 줄에는 테스트 케이스의 수 C (C ≤ 100)가 주어집니다. 각 테스트 케이스의 첫 줄에는 공연장을 대여할 수 있는 날들의 수 N (1 ≤ N ≤ 1000)과 이미 섭외한 공연 팀의 수 L (1 ≤ L ≤ 1000, L ≤ N)이 주어집니다. 그 다음 줄에는 N개의 숫자로 공연장 대여 비용이 날짜별로 주어집니다. 모든 비용은 100 이하의 자연수입니다.

### 출력
입력에 주어지는 각 테스트 케이스마다 한 줄에 최소의 평균 대여 비용을 출력합니다. ![10^{-7}](https://render.githubusercontent.com/render/math?math=10^{-7}) 이하의 절대/상대 오차가 있는 답은 정답 처리됩니다.

### 예제 입력
```
2
6 3
1 2 3 1 2 3 
6 2 
1 2 3 1 2 3
```

### 예제 출력
```
1.75000000000
1.50000000000
```
