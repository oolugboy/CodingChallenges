import scala.io.StdIn

object Solution {
  def cust_divide(aVal: Int, bVal: Int): Tuple4[Boolean, Int, Int, Int] = {
    bVal match {
      case 0 => (false, -1, -1, aVal)
      case _ => (true, bVal/aVal, bVal % aVal, aVal)
    }
  }
  def main(arr: Array[String]): Unit = {
    val n = StdIn.readInt()
    val a = StdIn.readLine().split(" ").map(x => x.toInt)
    val b = StdIn.readLine().split(" ").map(x => x.toInt)
   
    val tRes = List.range(0, n).map(x => cust_divide(a(x), b(x)))
    print(tRes)
  }
}
