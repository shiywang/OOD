package main

type Shape interface {
	accept(Visitor)
}

type Visitor func(shape Shape)

type Circle struct {
	Radius int
}

func (c Circle) accept(v Visitor) {
	v(c)
}

type Rectangle struct {
	Width, Heigh int
}

func (r Rectangle) accept(v Visitor) {
	v(r)
}

func JsonVisitor(shape Shape) {

}

func XmlVisitor(shape Shape) {

}

func main() {
	c := Circle{10}
	r := Rectangle{10, 15}

	shapes := []Shape{c, r}

	for _, s := range shapes {
		s.accept(JsonVisitor)
		s.accept(XmlVisitor)
	}

}
