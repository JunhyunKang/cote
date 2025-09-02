#include <bits/stdc++.h>
using namespace std;

// 전역 상수입니다. MAX_HEIGHT는 산의 높이 최대값을 나타내며, SEG_TREE_SIZE는 세그먼트 트리 배열의 크기를 나타냅니다.
const int MAX_HEIGHT = 1000000; // 산의 높이 최대값입니다.
const int SEG_TREE_SIZE = 4000005;  // 세그먼트 트리 배열의 크기입니다. (4 * MAX_HEIGHT + 여분의 공간을 포함합니다.)

// 전역 세그먼트 트리 배열입니다.
// segTree[node]는 해당 노드가 담당하는 구간 내에서 가장 큰 DP 값을 저장합니다.
int segTree[SEG_TREE_SIZE];
// segIndex[node]는 segTree[node]의 최대 DP 값을 갖는 산의 높이를 저장합니다.
int segIndex[SEG_TREE_SIZE];

// 각 산의 높이 별로 DP 값을 저장하는 버킷(스택)을 관리합니다.
// dpBuckets[height]는 해당 높이를 가진 산들의 DP 값들을 저장하며, 가장 위에 있는 값이 현재 최대 DP 값입니다.
vector<int> dpBuckets[MAX_HEIGHT + 1];

// 현재 지도(보드)의 상태를 유지하기 위한 벡터입니다.
// mountainHeights는 산들의 높이를 순서대로 저장하는 벡터입니다.
vector<int> mountainHeights;
// mountainDP는 각 산에 해당하는 DP 값을 순서대로 저장하는 벡터입니다.
vector<int> mountainDP;

// 세그먼트 트리 업데이트 함수입니다.
// 이 함수는 특정 'height' 위치에 대해서 'dpValue'로 업데이트하며, 관련 내부 노드들도 함께 갱신합니다.
// node는 현재 세그먼트 트리의 노드 인덱스를 의미하며, segLeft와 segRight는 현재 노드가 담당하는 구간의 범위를 의미합니다.
void updateSegmentTree(int node, int segLeft, int segRight, int height, int dpValue) {
    // 현재 구간에 'height'가 포함되지 않으면 아무 작업도 수행하지 않습니다.
    if (height < segLeft || height > segRight) 
        return;
    // 만약 현재 노드가 리프 노드라면, 직접 dpValue와 해당 높이 값을 저장합니다.
    if (segLeft == segRight) {
        segTree[node] = dpValue;
        segIndex[node] = height;
        return;
    }
    // 현재 노드가 리프가 아니라면, 왼쪽 구간과 오른쪽 구간으로 나누어 재귀적으로 업데이트를 수행합니다.
    int mid = (segLeft + segRight) / 2;
    updateSegmentTree(node * 2, segLeft, mid, height, dpValue);
    updateSegmentTree(node * 2 + 1, mid + 1, segRight, height, dpValue);
    // 자식 노드들의 결과를 바탕으로 현재 노드의 값을 갱신합니다.
    // 만약 왼쪽 자식의 DP 값보다 오른쪽 자식의 DP 값이 크거나 같으면, 오른쪽 자식의 값을 현재 노드에 저장합니다.
    if (segTree[node * 2] <= segTree[node * 2 + 1]) {
        segTree[node] = segTree[node * 2 + 1];
        segIndex[node] = segIndex[node * 2 + 1];
    } else {
        // 그렇지 않으면, 왼쪽 자식의 값을 저장합니다.
        segTree[node] = segTree[node * 2];
        segIndex[node] = segIndex[node * 2];
    }
}

// 세그먼트 트리 질의 함수입니다.
// 이 함수는 [queryLeft, queryRight] 구간 내에서 최대 DP 값을 반환합니다.
// node는 현재 노드 인덱스이며, segLeft와 segRight는 현재 노드가 담당하는 구간의 범위를 나타냅니다.
int querySegmentTree(int node, int segLeft, int segRight, int queryLeft, int queryRight) {
    // 현재 구간이 [queryLeft, queryRight]와 겹치지 않으면 0을 반환합니다.
    if (segRight < queryLeft || segLeft > queryRight) 
        return 0; // 겹치지 않으면 최소값인 0을 반환합니다.
    // 현재 구간이 질의 구간 안에 완전히 포함되면, 현재 노드의 값을 반환합니다.
    if (queryLeft <= segLeft && segRight <= queryRight)
        return segTree[node];
    // 현재 구간이 부분적으로 겹치는 경우, 왼쪽과 오른쪽 자식에 대해 재귀적으로 질의를 수행합니다.
    int mid = (segLeft + segRight) / 2;
    int leftQuery = querySegmentTree(node * 2, segLeft, mid, queryLeft, queryRight);
    int rightQuery = querySegmentTree(node * 2 + 1, mid + 1, segRight, queryLeft, queryRight);
    // 왼쪽과 오른쪽 자식의 결과 중 더 큰 값을 반환합니다.
    return max(leftQuery, rightQuery);
}

// 초기 지도(보드)를 설정하는 함수입니다.
// numMountains는 초기 산의 개수를 나타내며, initialMountains 벡터에는 각 산의 높이가 순서대로 저장되어 있습니다.
void initializeBoard(int numMountains, const vector<int>& initialMountains) {
    // 모든 가능한 높이에 대해 dpBuckets를 초기화합니다.
    // 모든 높이에 대해 처음에는 0 값을 넣어서 기본값을 설정합니다.
    for (int height = 1; height <= MAX_HEIGHT; height++) {
        dpBuckets[height].push_back(0);
    }
    // 왼쪽부터 오른쪽으로 각 산을 처리하면서 DP 값을 계산합니다.
    for (int i = 0; i < numMountains; i++) {
        int currentHeight = initialMountains[i];
        // 현재 산의 DP 값은 현재 산보다 낮은 모든 산들 중 최대 DP 값에 1을 더한 값입니다.
        // 이때 querySegmentTree를 사용하여 높이가 1부터 currentHeight - 1인 산들에서 최대 DP 값을 질의합니다.
        int dpValue = 1 + querySegmentTree(1, 1, MAX_HEIGHT, 1, currentHeight - 1);
        // 계산된 DP 값을 현재 산의 높이에 해당하는 버킷에 추가합니다.
        dpBuckets[currentHeight].push_back(dpValue);
        // 산의 높이와 DP 값을 각각 mountainHeights와 mountainDP 벡터에 저장합니다.
        mountainHeights.push_back(currentHeight);
        mountainDP.push_back(dpValue);
        // 세그먼트 트리에서 해당 높이에 대해 DP 값을 갱신합니다.
        updateSegmentTree(1, 1, MAX_HEIGHT, currentHeight, dpValue);
    }
}

// 새로운 산을 추가하는 함수입니다.
// 이 함수는 지도(보드)의 오른쪽 끝에 주어진 'height'를 가진 산을 추가합니다.
void addMountain(int height) {
    // 새로운 산의 DP 값을 계산합니다.
    // 새로운 산의 DP 값은 높이가 1부터 height - 1인 산들 중 최대 DP 값에 1을 더한 값입니다.
    int dpValue = 1 + querySegmentTree(1, 1, MAX_HEIGHT, 1, height - 1);
    // 계산된 DP 값을 해당 높이의 버킷에 추가합니다.
    dpBuckets[height].push_back(dpValue);
    // 산의 높이와 DP 값을 각각 mountainHeights와 mountainDP 벡터에 추가합니다.
    mountainHeights.push_back(height);
    mountainDP.push_back(dpValue);
    // 세그먼트 트리에서 해당 높이에 대해 DP 값을 업데이트합니다.
    updateSegmentTree(1, 1, MAX_HEIGHT, height, dpValue);
}

// 지도(보드)에서 가장 오른쪽에 위치한 산을 제거하는 함수입니다.
void removeLastMountain() {
    // 삭제할 산의 높이를 가져옵니다.
    int height = mountainHeights.back();
    // 산의 높이를 저장한 벡터에서 마지막 원소를 제거합니다.
    mountainHeights.pop_back();
    // 산의 DP 값을 저장한 벡터에서 마지막 원소를 제거합니다.
    mountainDP.pop_back();
    // 해당 높이에 대한 버킷에서 마지막 DP 값을 제거합니다.
    dpBuckets[height].pop_back();
    // 삭제 후 해당 높이에서 남아있는 DP 값은 버킷의 맨 위에 있는 값입니다.
    int newDpValue = dpBuckets[height].back();
    // 세그먼트 트리를 해당 높이에서 새로운 DP 값으로 업데이트합니다.
    updateSegmentTree(1, 1, MAX_HEIGHT, height, newDpValue);
}

// 등산 시뮬레이션을 수행하는 함수입니다.
// 이 함수는 케이블 카를 이용할 수 있는 산의 인덱스가 cableCarMountainIndex (1-indexed)라고 가정하고,
// 시뮬레이션을 통하여 얻을 수 있는 최대 점수를 계산하여 출력합니다.
void simulateHiking(int cableCarMountainIndex) {
    // 시뮬레이션의 점수는 다음의 계산 방식에 따릅니다.
    // 1) 케이블 카 산의 DP 값 (mountainDP[cableCarMountainIndex - 1]) 에서 1을 뺀 값과
    // 2) 현재 지도에 존재하는 모든 산들 중 최대 DP 값 (세그먼트 트리 루트의 값, segTree[1])의 합에
    // 3) 1,000,000을 곱한 후, 4) 마지막에 현재 지도에서 최대 DP 값을 갖는 산의 높이 (segIndex[1])를 더합니다.
    // 이로써 최종 점수를 계산합니다.
    long long score = (long long) 1000000 * ( (mountainDP[cableCarMountainIndex - 1] - 1) + segTree[1] ) + segIndex[1];
    // 계산된 점수를 출력합니다.
    cout << score << "\n";
}

// main 함수입니다. 입력을 받아서 해당 명령들을 처리하는 역할을 합니다.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 명령의 총 개수를 입력받습니다.
    int numQueries;
    cin >> numQueries;
    
    // 각 명령을 순차적으로 처리합니다.
    while(numQueries--) {
        int queryType;
        cin >> queryType;
        
        // 만약 명령 타입이 100 (빅뱅)이라면, 초기 지도를 생성합니다.
        if(queryType == 100) {
            int numMountains;
            cin >> numMountains;
            vector<int> initialMountains;
            // numMountains개의 산의 높이를 입력받아서 initialMountains 벡터에 저장합니다.
            for (int i = 0; i < numMountains; i++) {
                int height;
                cin >> height;
                initialMountains.push_back(height);
            }
            // 초기 지도를 설정하는 함수를 호출하여 보드를 초기화합니다.
            initializeBoard(numMountains, initialMountains);
        }
        // 만약 명령 타입이 200 (우공이산)이라면, 새로운 산을 추가합니다.
        else if(queryType == 200) {
            int height;
            cin >> height;
            // 오른쪽 끝에 새로운 산을 추가하는 함수를 호출합니다.
            addMountain(height);
        }
        // 만약 명령 타입이 300 (지진)이라면, 가장 오른쪽에 있는 산을 제거합니다.
        else if(queryType == 300) {
            // 지진 명령으로 인해 마지막 산을 제거하는 함수를 호출합니다.
            removeLastMountain();
        }
        // 만약 명령 타입이 400 (등산 시뮬레이션)이라면, 등산 시뮬레이션을 수행합니다.
        else if(queryType == 400) {
            int cableCarMountainIndex;
            cin >> cableCarMountainIndex;
            // 케이블 카를 사용할 수 있는 산의 인덱스를 기반으로 시뮬레이션을 수행하여 점수를 계산하고 출력하는 함수를 호출합니다.
            simulateHiking(cableCarMountainIndex);
        }
    }
    
    // 프로그램을 종료합니다.
    return 0;
}
