#!/usr/bin/env python3
from typing import Sequence


def counting_sorted(arr: Sequence, max_index: int):
    count = [0 for _ in range(max_index + 1)]

    ret = [0 for _ in arr]

    for x in arr:
        count[x] += 1

    for i in range(1, max_index + 1):
        count[i] += count[i - 1]

    for i in range(len(arr)):
        ret[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1

    return ret
