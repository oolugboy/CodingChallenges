import scala.io.StdIn
import scala.math.min

object Solution {
  def main(args: Array[String]): Unit = {
    val nKLine = StdIn.readLine().split(" ").map(x => x.toInt)
    val n = nKLine(0)
    val k = nKLine(1)

    println((3 * n) + min(n - k, k - 1))
  }
}
