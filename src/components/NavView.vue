<template>
  <nav class="fixed bottom-0 lg:sticky lg:h-screen">
    <ul
      class="nav py-8 flex lg:flex-col items-center xl:items-start justify-around lg:justify-start lg:gap-10 w-screen lg:w-20 xl:w-48 lg:h-screen bg-gradient-to-t from-white backdrop-blur-sm lg:mt-20 xl:mr-12"
    >
      <li>
        <router-link to="/" class="flex gap-4 opacity-40">
          <img src="@/assets/icons/ic_home.svg" alt="" />
          <h2 class="hidden xl:block">Home</h2>
        </router-link>
      </li>
      <li>
        <router-link to="/about" class="flex gap-4 opacity-40">
          <img src="@/assets/icons/ic_about.svg" alt="" />
          <h2 class="hidden xl:block">About</h2>
        </router-link>
      </li>
      <li>
        <router-link to="/team" class="flex gap-4 opacity-40">
          <img src="@/assets/icons/ic_team.svg" alt="" />
          <h2 class="hidden xl:block">Team</h2>
        </router-link>
      </li>
    </ul>
  </nav>
</template>

<script>
export default {
  name: 'NavView',
}
</script>

<style lang="scss">
nav {
  li {
    a {
    &.router-link-exact-active {
      opacity: 1;
    }
  }
  }
}
</style>
