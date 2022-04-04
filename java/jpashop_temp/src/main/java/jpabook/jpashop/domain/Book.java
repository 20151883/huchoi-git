package jpabook.jpashop.domain;

import javax.persistence.Entity;

@Entity
public class Book extends Item{
    private String Author;

    public String getAuthor() {
        return Author;
    }

    public void setAuthor(String author) {
        Author = author;
    }

    public String getIsbn() {
        return isbn;
    }

    public void setIsbn(String isbn) {
        this.isbn = isbn;
    }

    private String isbn;
}
