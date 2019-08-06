# PICK BASIC Examples

## Resources

Pick For Professionals (PFP)

Code examples:

* 67
* 76

## Loop

From PFP#8

```vb
# ID is a string

BINARYID = 0
IDLENGTH = LEN(ID)
FOR POSITION = 1 TO IDLENGTH
  BINARYID = SEQ(ID[POSITION,1]) + BINARYID*10
NEXT POSITION
GROUPNUM = REM(ID,MODULO)
FID = (GROUPNUM * SEPARATION) + BASE
```

