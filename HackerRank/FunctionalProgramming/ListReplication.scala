import scala.collection.mutable.ListBuffer
import scala.io.StdIn

def f(num: Int, arr: List[Int]): List[Int] = {
  arr.map(x => Entry.repPrint(x, num)).flatten
}

object Entry {
  def repPrint(value: Int, amLeft: Int): List[Int] = 
  {
    amLeft match {
      case 0 => List[Int]()
      case _ => {
        value :: repPrint(value, amLeft - 1)
      }
    }
  } 

  def getInput(): ListBuffer[Int] = 
  {
    var resList = ListBuffer[Int]()
    try
    {
      for(i <- 0 to (10 - 1))
      {
        resList += StdIn.readInt()
      }
      resList
    }
    catch
    {
      case ex: java.lang.NumberFormatException => resList
    }
    finally
    {
      resList;
    }
  }

  def main(args: Array[String]): Unit = 
  {
    val n = StdIn.readInt()
    getInput().map(x => repPrint(x, n))
  }
}
