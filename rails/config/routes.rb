Rails.application.routes.draw do
  resources :books

  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html
  get "default" => "hello#default" #사용자가 하이퍼링크를 클릭하면 이렇게 처리

  match ":controller(/:action (/:id))", via: [:get, :post, :patch] #사용자가 url을 입력하면 이렇게 처리
end
