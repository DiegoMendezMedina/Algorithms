{-
 Diego Méndez Medina

 *Consider the problem of adding two n-bit binary integers, 
 *stored in two n-element array A and B. 
 *The sum of the two integers should be stored in binary form in an 
 *(n+1)-element array C.
 -----------------------------------------
 This haskell solutions doesn't stores the binary integers on arrays.
 Instead it is used a data type 'Binary'. The solution can add any two elements
 of de data type Binary.
 Check the tests.
 ........................................
 For any comment or suggestion feel free to make a pull request or contact me
 at diegomm@ciencias.unam.mx 
-}
module Binary where

data Binary = Void | Zero(Binary) | One(Binary)

{-
Binary numbers may be written :
1_{10} = 1  = One Void
2_{10} = 10 = Zero(One Void)
3_{10} = 11 = One(One Void)
.
.
.
And so on
-}

instance Show (Binary) where
  show a = show_bin a

instance Eq(Binary) where
  (==) a b = eqBin a b

-- | show_bin: Aux function to print the Binary elements.
show_bin :: Binary -> String
show_bin (Zero Void) = " 0"
show_bin (One Void) = " 1"
show_bin (Zero xs) =  show_bin xs ++ " 0"
show_bin (One xs) =  show_bin xs ++ " 1"

-- | eqBin: Aux function to tell if two Binary elements are the same.
eqBin :: Binary -> Binary -> Bool
eqBin Void Void = True
eqBin x Void    = False
eqBin Void x    = False
eqBin (One xs)(One ys)   = eqBin xs ys
eqBin (Zero xs)(Zero ys) = eqBin xs ys
eqBin (One xs)(Zero ys)  = False
eqBin (Zero xs)(One ys)  = False

-- | two_bit_add: Function that adds two Binary elements.
two_bit_add :: Binary -> Binary -> Binary
two_bit_add Void Void = Void
two_bit_add x Void =  x
two_bit_add Void x = x
two_bit_add (Zero x) (Zero y) = Zero(two_bit_add x y)
two_bit_add (One x)(Zero y) = One(two_bit_add x y)
two_bit_add (Zero x)(One y) = One(two_bit_add x y)
two_bit_add (One x)(One y) = Zero(three_bit_add (One Void) x y)

-- | three_bit_add: Aux function to calculate the two_bit_add. Simulates
--                  the bit carry.
three_bit_add :: Binary -> Binary -> Binary -> Binary
three_bit_add (One Void) Void Void = One Void
three_bit_add (One Void) Void   x  = two_bit_add(One Void) x
three_bit_add (One Void)   x  Void = two_bit_add(One Void) x
three_bit_add (One Void)(Zero x)(One y)  = Zero(two_bit_add x y)
three_bit_add (One Void)(One x)(Zero y)  = Zero(two_bit_add x y)
three_bit_add (One Void)(Zero x)(Zero y) = One(two_bit_add x y)
three_bit_add (One Void)(One x)(One y)   = One(three_bit_add (One Void) x y)


--------------------------------------------------------------------------------
--------                             TESTS                            ----------
--------------------------------------------------------------------------------

zero = Zero Void
one = One Void
two = Zero (One Void)
three = One(One Void)
four = Zero(Zero(One Void))
five = One(Zero(One Void))
eight = two_bit_add three five
ten = Zero(One(Zero(One Void)))
ten' = two_bit_add five five
twenty = (two_bit_add ten ten)
twenty_eight' = two_bit_add twenty eight
twenty_eight = two_bit_add (two_bit_add ten ten) eight
one_hundred = Zero(Zero(One(Zero(Zero(One(One Void))))))
one_hundred_twenty_eight = Zero(Zero(Zero(Zero(Zero(Zero(Zero(One Void)))))))

-- eq1 instance
eq1 = eqBin (two_bit_add three two) five
--returns True

--eq2 instance
eq2 = (two_bit_add four (two_bit_add three three)) == ten
-- return True

--eq3 instance
eq3 = eqBin two three
-- return False

--eq4 instance
eq4 = two == two_bit_add one zero
--return False

--eq5 instance
eq5 = one_hundred_twenty_eight == two_bit_add one_hundred twenty_eight
-- return False. Although they represent the same value, are different numbers

--eq6 instance
eq6 = twenty_eight == twenty_eight'
-- return True
