import scala.io.StdIn

def f(arr: List[Int]): List[Int] = {
  Singleton.solve(arr.length, arr)
}

object Singleton
{
  def getInput(amount: Int): List[Int] = {
    amount match {
      case 0 => List[Int]()
      case _=> StdIn.readInt()::getInput(amount - 1)
    }
  }

  def solve(amount: Int, values: List[Int]): List[Int] = {
    (values.foldLeft((0, List[Int]())) { (acc, x) => {
      (acc._1 % 2) match {
        case 1 => (acc._1 + 1, acc._2 ::: List[Int](x))
        case _=> (acc._1 + 1, acc._2)
      }
    } })._2
  }

  def main(args: Array[String]): Unit = {
    solve(8, getInput(8)).map(x => println(x)) 
  }
}
