package main

import (
	"crypto/tls"
	"fmt"
	"time"
)

type Server struct {
	Addr     string
	Port     int
	Protocol string
	Timeout  time.Duration
	MaxConns int
	TLS      *tls.Config
}

type ServerBuilder struct {
	server  Server
	errMesg error
}

type Option func(*Server)

func (s *ServerBuilder) WithAddr(ip string) *ServerBuilder {
	s.server.Addr = ip
	return s
}

func (s *ServerBuilder) WithPort(port int) *ServerBuilder {
	s.server.Port = port
	return s
}

func (s *ServerBuilder) WithMaxConn(conn int) *ServerBuilder {
	s.server.MaxConns = conn
	return s
}

func (s *ServerBuilder) WithProtocol(poto string) *ServerBuilder {
	s.server.Protocol = poto
	return s
}

func (s *ServerBuilder) WithTLS(tls *tls.Config) *ServerBuilder {
	s.server.TLS = tls
	return s
}

func (s *ServerBuilder) Build() (*Server, error) {
	return &s.server, s.errMesg
}

func main() {
	sb := ServerBuilder{}
	server, err := sb.WithAddr("127.0.0.1").WithPort(90).WithProtocol("udp").
		WithMaxConn(1024).Build()

	fmt.Println(server, err)
}
