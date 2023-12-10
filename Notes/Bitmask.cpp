// Set Bit
x = x | 1 << pos; 

// ...

// Clear Bit
x = x & ~(1 << pos); 

// ...

// Toggle
x = x ^ 1 << pos; 

// ...

// Check
if (x & (1 << pos)) 
{
  // Bit is Set
} 
else 
{
  // Bit is Unset
} 

// ...

// Print Bitmask
for (int i = sizeof(mask) * 8 - 1; i >= 0; i--) 
{
  int bit = (mask >> i) & 1;
  cout << bit;
}
cout << endl;