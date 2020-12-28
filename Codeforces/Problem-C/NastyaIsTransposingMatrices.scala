import scala.io.StdIn
import scala.math.min

object Solution {
  def printMatrix(matrix: Array[Array[Int]], n: Int, m: Int, i: Int, j: Int): Unit = {
    (i < n) match {
      case false => Unit
      case true => {
        (j < m) match {
          case false => {
            println("")
            printMatrix(matrix, n, m, (i + 1), 0)
          }
          case true => {
            print(matrix(i)(j) + " ")
            printMatrix(matrix, n, m, i, (j + 1))
          }
        }
      }
    }
  }
  def getDiagList(matrix: Array[Array[Int]], currInds: Tuple2[Int, Int], amount: Int): List[Int] = {
    amount match {
      case 0 => Nil
      case _ => matrix(currInds._1)(currInds._2) :: getDiagList(matrix, (currInds._1 - 1, currInds._2 + 1), amount - 1)
    }
  }
  def compareList(aList: List[Int], bList: List[Int]): Boolean = {
    aList match {
      case a :: aRest => {
        bList match {
          case b :: bRest => (a == b) && compareList(aRest, bRest)
          case Nil => true
        }
      }
      case Nil => true
    }
  }
  def main(args: Array[String]): Unit = {
    val nM = StdIn.readLine().split(" ").map(x => x.toInt)
    val n = nM(0)
    val m = nM(1)

    val aMatrix = Array.range(0, n).map(x => StdIn.readLine().split(" ").map(y => y.toInt))
    val bMatrix = Array.range(0, n).map(x => StdIn.readLine().split(" ").map(y => y.toInt))

    val colStartInds = Array.range(0, n).map(x => (x, 0))
    val rowStartInds = Array.range(1, m).map(x => ((n - 1), x))

    val startInds = colStartInds ++ rowStartInds
    val aDiagLists = startInds.map(x => getDiagList(aMatrix, x, min(x._1 + 1, m - x._2)).sorted)
    val bDiagLists = startInds.map(x => getDiagList(bMatrix, x, min(x._1 + 1, m - x._2)).sorted)

    val res = Array.range(0, startInds.size).toList.foldLeft(true) { (acc, x) => acc && compareList(aDiagLists(x), bDiagLists(x)) }

    res match {
      case true => println("YES")
      case false => println("NO")
    }
  }
}
