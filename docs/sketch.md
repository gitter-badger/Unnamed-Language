# Sketch Area #
This area contains general ideas, sketches, etc.

filename: Something
```
public (:) enter
{
  // Declarations
  Type name;       // Default ctor always invoked

  // Function/method call statements, no expressions on the right side?
  1u result: status = name.setValue(number: 100);
  1u result = name.setValue(number: 100)~status;
}

public (64u factorial : 64u of) computeFactorial
{
  if (of == 2)
    return factorial: of;
  return factorial: of * computeFactorial(of: of - 1)~factorial;
}
```

Okay I think I got the entire language now...

```
public (:) enter
{
  Player a;
  a.getObject()~object.getPosition()~x.toFloat()~value;
  value~(x~(object~a.getObject()).getPosition()).toFloat();

  system.out << "Enter the number of rows in pyramid of stars you wish to see ");
  32u n(system.in.read32u()~result);
  32u temp = n;
  for (32u row = 1 ; row <= n; row++)
  {
    for (32u c = 1 ; c < temp; c++)
      system.out << " ";
    temp--;
    for (32u c = 1 ; c <= 2 * row - 1; c++)
      system.out << "*";

    system.out << system.linefeed;
  }
}
```
```
public (:) enter
{
  call(number: 100);
}

public (: 32u number) call
{

}
```

public (:) enter
{
  String inputfile = System::Command("--file")~string;
  TokenStream tokenstream = Lexer::lex(inputfile)~stream;

  SymbolTable unrecognizedsymbols;
  SymbolTable symboltable;

  do (unrecognizedsymbols.isEmpty()~value == false)
  {
    AbstractSyntaxTree ast: abstractsyntaxtree,
    SymbolTable unrecognized: nondeclared
      = Parser::parse
      (
        stream: adr tokenstream,
        symboltable: adr symboltable
      );

    unrecognizedsymbols += nondeclared; // Set addition
  }
}























