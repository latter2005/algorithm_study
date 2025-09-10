import java.util.*
import kotlin.math.max




class Solution {
    fun solution(id_list: Array<String>, report: Array<String>, k: Int): IntArray {
        var answer: IntArray = IntArray(id_list.size) {0}

        val mp = mutableMapOf<String, User>()

        id_list.forEachIndexed { idx, id -> mp[id] = User(idx, id) }

        for (s in report) {
            val split = s.split(' ')
            val reportUser = mp[split[0]]!!
            val reportedUser = mp[split[1]]!!

            if(!reportedUser.reportedBy.contains(reportUser)){
                reportedUser.reportedBy.add(reportUser)
                reportedUser.reportedCount++
            }
        }

        mp.forEach{key, user ->
            if(user.reportedCount >= k){
                user.reportedBy.forEach { reportUser ->
                    answer[reportUser.idx]++
                }
            }
        }


        return answer
    }

    class User(
        val idx: Int,
        val id: String,
        var reportedCount: Int = 0,
        val reportedBy: MutableSet<User> = mutableSetOf(),
    )
}