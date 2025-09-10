import kotlin.math.ceil
import kotlin.math.max

fun main() {
    val s = Solution()


    println(
        s.solution(
            intArrayOf(180, 5000, 10, 600),
            arrayOf("05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT")
        ).joinToString()
    )
}



class Solution {
    fun solution(fees: IntArray, records: Array<String>): IntArray {
        val answer = mutableListOf<Int>()

        val mp = sortedMapOf<String, Car>()

        for (record in records) {
            val split = record.split(' ', ':')
            val time = split[0].toInt() * 60 + split[1].toInt()
            val car = mp.computeIfAbsent(split[2]) { Car(null) }

            when(split[3]) {
                "IN" -> car.inTime = time
                "OUT" -> {
                    car.totalTime += time - car.inTime!!
                    car.inTime = null
                }
            }
        }

        mp.forEach { key, value ->
            if(value.inTime != null){
                value.totalTime += 1439 - value.inTime!!
            }

            var cost = fees[1]
            var time = value.totalTime
            time = max(time - fees[0], 0)

            cost += (ceil(time.toDouble() / fees[2])).toInt() * fees[3]

            answer.add(cost)
        }

        return answer.toIntArray()
    }



    class Car(
        var inTime: Int?,
        var totalTime: Int = 0
    )
}