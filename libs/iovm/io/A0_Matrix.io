Matrix do(
    asString := method(
        result := "matrix("
        self toList foreach(v, result := result  .. "\n [" .. v join(", ").. "]" )
        result := result  .. ")"
        result)
)
