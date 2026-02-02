fun main(args: Array<String>) {
    val T = readLine()!!.toInt()

    repeat(T) {
        var day = readLine()!!.toInt()
        val arr = readLine()!!.split(" ").map { it.toInt() }

        // 주가가 계속 감소하는지 내림차순인지 확인
        val desc = arr.sortedDescending()
        var isDescending = true

        for( i in 0 until arr.size ) {
            if(arr[i] != desc[i]) isDescending = false
        }

        if(isDescending) {
            println(0)
        } else {
            var result = 0L // 최대 이익

            // 7 7 10 6
            // 7 8 10 6
            // 10 7 7 6

            // 큰 수 앞에 작은 수가 올 때

            // 제일 큰 수를 찾고, 그 수보다 작은 수가 앞에 몇 걔?
            // 그 다음 큰 수를 찾고, 그 수보다 작은 수가 앞에 몇 개?
            var idx = 0

            while(day > 0) {
                var max = desc[idx]
                val count = arr.indexOf(max) + 1

                if(count <= day) {
                    result += count * max

                    for(i in 0 until count) {
                        result -= arr[i]
                    }

                    day -= count
                }

                idx--
            }

            println(result)
        }
    }
}