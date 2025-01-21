// https://www.codewars.com/kata/566fc12495810954b1000030/cpp

class CountDig
{
    public:
        static int nbDig(int n, int d)
        {
            int d_count{ 0 };

            for (int k{ 0 }; k <= n; k++)
            {
                int x{ k * k };

                do
                {
                    if (x % 10 == d)
                    {
                        d_count++;
                    }

                    x /= 10;                    
                }
                while (x > 0);
            }

            return d_count;
        }
};