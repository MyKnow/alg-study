#!/usr/bin/env kotlin

fun main(args: Array<String>) {

    // 도현이는 집이 많아서 좋겠다..
    val (N, C) = readLine()!!.split(" ").map { it.toInt() }
    val homes = IntArray(N) { readLine()!!.toInt() }.sorted()

    // println(homes)
    // 한 집에는 공유기를 하나만 설치할 수 있고,
    // 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치


    // 1 2    4      8 9
    // 1 2  4    6   9

    // 1 4 9 (o)
    // 1 6 9 (o)
    // 1 2 9 (x)

    // 가장 인접한 두 공유기 사이의 거리가 최대가 되게 하는...

    // 우리가 구하고자 하는 것은
    // 가장 인접한 두 공유기 사이의 거리..
    // left, right를 어떻게?

    // 가장 인접한 두 공유기 사이의 거리가 최소, 최대가 되게 하는

    // 1, 2에 설치 or 8, 9에 설치 -> 거리가 최소
    // 9, 4에 설치해도 어차피 1에 최대 멀게 설정해도 1, 4에 설치

    var answer = 0

    // 공유기의 개수가 2이면,
    // 오름차순 정렬해서 양쪽 끝의 거리가 최대거리
    if(C == 2) {
        answer = homes[N-1] - homes[0]
    } else {
        val left = 1  // // 두 인접한 집 사이의 거리 최소
        val right = homes[N-1] - homes[0] // 최대

        while(left <= right) {
            val mid = (left + right) / 2

            for( i in 1 until N ) {

            }
        }
    }

    print(answer)
}