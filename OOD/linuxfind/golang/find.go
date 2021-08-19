package main

import "fmt"

type File struct {
	name     string
	size     int
	fileType int
	isDir    bool
	children []*File
}

func (f *File) AddChildren(child []*File) {
	for _, v := range child {
		f.children = append(f.children, v)
	}
}

func NewFile(name string, size int, fileType int, isDir bool) *File {
	f := new(File)
	f.name = name
	f.size = size
	f.fileType = fileType
	f.isDir = isDir
	return f
}

func NewMinSizeFilter(minSize int) *MinSizeFilter {
	nf := new(MinSizeFilter)
	nf.minSize = minSize
	return nf
}

func NewFileTypeFilter(ftype int) *FileTypeFilter {
	tf := new(FileTypeFilter)
	tf.fileType = ftype
	return tf
}

type Filter interface {
	apply(*File) bool
}

type FileTypeFilter struct {
	fileType int
}

type MinSizeFilter struct {
	minSize int
}

func (mf MinSizeFilter) apply(f *File) bool {
	return mf.minSize <= f.size
}

func (ff FileTypeFilter) apply(f *File) bool {
	return ff.fileType == f.fileType
}

func FindWithFilters(file *File, filter []Filter) []*File {
	var output []*File
	if len(file.children) == 0 {
		fmt.Println("Exception Dir is Empty !!")
		return []*File{}
	} else {
		for _, child := range file.children {
			if child.isDir {
				output = append(output, FindWithFilters(child, filter)...)
			} else {
				selectFile := false
				for _, v := range filter {
					if v.apply(child) {
						selectFile = true
						break
					}
				}
				if selectFile {
					output = append(output, child)
				}
			}
		}
	}
	return output
}

func main() {
	f := NewFile("5", 0, 0, true)
	f1 := NewFile("1", 100, 1, false)
	f2 := NewFile("2", 1, 2, false)
	f3 := NewFile("3", 200, 1, false)
	f4 := NewFile("4", 2, 100, false)
	f.AddChildren([]*File{f1, f2, f3, f4})
	filter1 := NewMinSizeFilter(99)
	filter2 := NewFileTypeFilter(2)
	out := FindWithFilters(f, []Filter{filter1, filter2})
	for _, v := range out {
		fmt.Println("File name is ", v.name)
	}
}
