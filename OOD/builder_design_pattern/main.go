package main

import "fmt"

type ShowStatus interface {
	ShowSalary() int
	ShowWorkAddress() string
}

type Person struct {
	name, address, city, zip string
	workAddress, company     string
	salary                   int
}

type PersonBuilder struct {
	person *Person
}

func NewPersonBuilder() *PersonBuilder {
	return &PersonBuilder{person: &Person{}}
}

func (b *PersonBuilder) LivesIn(city string) *PersonBuilder {
	b.person.city = city
	return b
}

func (b *PersonBuilder) WorksAt(company string) *PersonBuilder {
	b.person.company = company
	return b
}

func (b *PersonBuilder) WorksIn(address string) *PersonBuilder {
	b.person.workAddress = address
	return b
}

func (b *PersonBuilder) SalaryIs(salary int) *PersonBuilder {
	b.person.salary = salary
	return b
}

func (b *PersonBuilder) Build() *Person {
	return b.person
}

func (p *Person) ShowSalary() int {
	return p.salary
}

func (p *Person) ShowWorkAddress() string {
	return p.workAddress
}

func main() {
	pb := NewPersonBuilder().LivesIn("Amherst").WorksAt("Umass").SalaryIs(1000).WorksIn("1F Brandywine")
	person := pb.Build()

	fmt.Println(person.ShowSalary())
	fmt.Println(person.ShowWorkAddress())
}
