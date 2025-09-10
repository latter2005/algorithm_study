import kotlin.math.max
class Solution {

    private fun dfs(s: Int, w: Int) {

        if (s > w) MAX = max(s, MAX)
        else return


        for ((a, b) in EDGE) {
            if (VISITED[a] && !VISITED[b]) {
                val (ns, nw) = if (INFO[b] == 0) (s + 1 to w) else (s to w + 1);
                VISITED[b] = true
                dfs(ns, nw)
                VISITED[b] = false
            }
        }

    }

    fun solution(info: IntArray, edges: Array<IntArray>): Int {

        INFO = info
        EDGE = edges

        VISITED[0] = true
        dfs(1, 0)

        return MAX
    }

    companion object {
        var MAX = 0
        var INFO: IntArray = intArrayOf()
        var EDGE: Array<IntArray> = arrayOf()
        val VISITED = Array(18) { false }

    }
}