import scala.io.StdIn

object Solution {
  def chaptersLeft(lastPage: Int, currentLeft: Int, page: Int): Int = {
    currentLeft match {
      case 1 => 1
      case _ => (page > lastPage) match {
        case true => (currentLeft - 1)
        case false => (currentLeft)
      }
    }
  }
  def main(args: Array[String]): Unit = {
    val n = StdIn.readInt() 
    val lastPages = (1 to n).toList.map(x => (StdIn.readLine()).split(" ")(1).toInt)
    val page = StdIn.readInt()
    val res = lastPages.foldLeft(n)((acc, x) => chaptersLeft(x, acc, page))
    println(res)
  }
}
