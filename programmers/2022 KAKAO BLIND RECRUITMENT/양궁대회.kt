import java.util.*
import kotlin.math.ceil
import kotlin.math.max

fun main() {
    val s = Solution()


    println(
        s.solution(
            10, intArrayOf(0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3)
        ).joinToString()
    )
}

class Solution {
    fun solution(n: Int, info: IntArray): IntArray {
        var answer: IntArray = intArrayOf()

        var dp = Array<Pair<Int, IntArray?>>(11) { Int.MIN_VALUE to null } //화살, 점수
        dp[0] = 0 to IntArray(11){0}

        for (i in 0 until 10) {

            val next = Array<Pair<Int, IntArray?>>(11) { Int.MIN_VALUE to null } //화살, 점수


            for (j in 0 until n + 1) {
                if (dp[j].second == null) continue

                if (next[j].first < dp[j].first || (next[j].first == dp[j].first && compareSame(dp[j].second!!, next[j].second!!))
                ) {
                    val l = dp[j].second!!.copyOf()
                    l[i] = 0
                    next[j] = dp[j].first to l
                }

                if (info[i] == 0 && j < n) {
                    val l = dp[j].second!!.copyOf()
                    l[i] = (1)
                    next[j + 1] = (dp[j].first + 10 - i) to l
                } else if (info[i] != 0 && j + info[i] + 1 <= n) {
                    val l = dp[j].second!!.copyOf()
                    l[i] = (info[i] + 1)
                    next[j + info[i] + 1] = dp[j].first + (10 - i) * 2 to l
                }
            }
            dp = next
        }

        var cSum = 0
        var mxIdx = -1
        var mx: Pair<Int, IntArray?> = -1 to null
        for (i in 0 until n + 1) {
            if(info[i] > 0) cSum += 10-i
            if (dp[i].first > mx.first || (dp[i].first == mx.first && compareSame(dp[i].second!!, mx.second!!))) {
                mxIdx = i
                mx = dp[i]
            }
        }
        if(mx.first <= cSum) return intArrayOf(-1)

        mx.second!![10] = (n - mxIdx)

        return mx.second!!
    }

    fun compareSame(a: IntArray, b: IntArray): Boolean {
        for (i in b.size - 1 downTo 0) {
            if (a[i] > b[i]) return true
            else if (a[i] == b[i]) continue
            else return false
        }
        return true
    }


}