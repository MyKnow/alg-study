# 상근이가 중복이 허용되는 카드덱을 가지고 있는데
# 그 중에서 특정 카드를 몇 개 가지고 있는 지 출력하면 된다.

N = int(input())
sanggeun_card = list(map(int, input().split()))
M = int(input())
card_numbers = list(map(int, input().split()))

# 1. defaultdict로 풀기
def solution_dd():
    from collections import defaultdict

    dd = defaultdict(int)
    for s in sanggeun_card:
        dd[s] += 1

    result = []
    for c in card_numbers:
        result.append(dd[c])

    return result

print(" ".join(map(str, solution_dd())))
