Rails.application.routes.draw do
  get 'welcome/index'
  # resources  :articles
  #match ':controller(/:action(/:id))', via:[:get, :post, :patch]
  root 'welcome#index'# root를 여러개 명시해 놓으면 에러가 발생함.
  # For details on the DSL available within this file, see https://guides.rubyonrails.org/routing.html
end

