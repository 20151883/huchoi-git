package jpabook2.jpashop2.controller;

import jpabook2.jpashop2.domain.item.Book;
import jpabook2.jpashop2.domain.item.Item;
import jpabook2.jpashop2.service.ItemService;
import lombok.RequiredArgsConstructor;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;

import java.util.List;

@Controller
@RequiredArgsConstructor
public class ItemController {
    private final ItemService itemService;

    @GetMapping("items/new")
    public String createForm(Model model){
        model.addAttribute("form", new BookForm());
        return "items/createItemForm";
    }

    @PostMapping("items/new")
    public String create(BookForm bookForm){
        Book book = new Book();
        book.setName(bookForm.getName());
        book.setPrice(bookForm.getPrice());
        book.setStockQuantity((bookForm.getStockQuantity()));
        book.setIsbn(bookForm.getIsbn());
        book.setAuthor(bookForm.getAuthor());

        itemService.save(book);
        return "redirect:/items";
    }

    @GetMapping("/items")
    public String list(Model model){
        List<Item> items = itemService.findItems();
        model.addAttribute("items", items);
        return "items/itemList";
    }

    @GetMapping("items/{itemId}/edit")//PostMapping이 아니고 GetMapping
    public String updateItemForm(@PathVariable("itemId") Long itemId, Model model){
        Book item = (Book)itemService.findOne(itemId);
        BookForm bookForm = new BookForm();
        bookForm.setId(item.getId());
        bookForm.setName(bookForm.getName());
        bookForm.setPrice(bookForm.getPrice());
        bookForm.setAuthor(bookForm.getAuthor());
        bookForm.setIsbn(bookForm.getIsbn());

        model.addAttribute("form", bookForm);
        return "items/updateItemForm";
    }

    @PostMapping("items/{itemId}/edit")
    public String updateItem(@PathVariable("itemId") Long itemId, Model model, BookForm bookForm){//{itemId} 값을 알지 못해도 ㄱㅊ (Form에 다 있음)
        Book book = new Book();
        book.setId(bookForm.getId());
        book.setPrice(bookForm.getPrice());
        book.setName(bookForm.getName());
        book.setStockQuantity(bookForm.getStockQuantity());
        book.setAuthor(bookForm.getAuthor());
        book.setIsbn(bookForm.getIsbn());

        itemService.save(book);
        return "redirect:/items";
    }
}
