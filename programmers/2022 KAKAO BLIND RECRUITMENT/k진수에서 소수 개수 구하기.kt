import java.util.*
import kotlin.math.max


fun main() {
    val s = Solution()


    println(
        s.solution(
            2, 8
        )
    )
}



class Solution {
    fun solution(n: Int, k: Int): Int {
        if(n <= 1) return 0

        var answer: Int = 0
        var mx = -1L

        val split = n.toString(k).split('0').filter{t -> t.isNotEmpty()}.map {
            val toLong = it.toLong()
            mx = max(mx, toLong)
            toLong
        }.toLongArray()




        split.forEach { t -> if(isPrime(t)){answer++} }

        return answer
    }

    fun isPrime(num: Long): Boolean {
        if (num <= 1) return false
        return (2..Math.sqrt(num.toDouble()).toLong()).none { num % it == 0L }
    }
}