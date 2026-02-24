const menuIcon = document.querySelector(".menu-icon");
const closeIcon = document.querySelector(".close-icon");
const headerButtons = document.querySelector(".header-buttons");

menuIcon.addEventListener("click", () => {
  headerButtons.classList.add("show-menu");
  menuIcon.classList.add("hide-menu");
  closeIcon.classList.add("show-menu");
});

closeIcon.addEventListener("click", () => {
  headerButtons.classList.remove("show-menu");
  closeIcon.classList.remove("show-menu");
  menuIcon.classList.remove("hide-menu");
});
