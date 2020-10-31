import scala.io.StdIn

def f(arr: List[Int]): List[Int] = {
  Singleton.reverse(arr)
}
object Singleton {
  def getInput(amount: Int): List[Int] = {
    amount match {
      case 0 => List[Int]()
      case _=> StdIn.readInt()::getInput(amount - 1)
    }
  }
  def reverse(values: List[Int]): List[Int] = {
    values match {
      case curr::others => reverse(others) ::: List[Int](curr)
      case Nil => Nil
    }
  }
  def main(args: Array[String]): Unit = {
    reverse(getInput(10)).map(x => println(x))
  }
}
