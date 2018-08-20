int max(int a[], int length)
{
   if (length == 1)
      return a[0];
   else {
      // find max value in rest of array
      int max_so_far = max(&a[1], length-1);
      // check if it's bigger than the first element
      return (a[0] > max_so_far) ? a[0] : max_so_far;
   }
}
